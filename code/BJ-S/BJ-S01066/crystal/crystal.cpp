#include <bits/stdc++.h>
using namespace std;
long long a[500000];
long long n,m,j;
long long maxx=0;
int find(int i){
	long long s=0;
	long long b[500000][2];
	for(int j=1;j<n;j++){
		if(a[j]-a[j-1]==i){
			b[s][0]=j-1;
			for(int z=j-1;z>=0;z--){
				if(a[z]==a[j-1])b[s][1]++;
				else{break;}
			}
			s++;
		}
	}
	if(s==0)return -1;
	long long m1=b[0][1],m2;
	for(int j=1;j<s;j++){
		if(m1<b[j][1]){
			m1=b[j][1];
			m2=b[j][0];
		}
	}
	return m2;}
int f2(){
	long long l=0,l2=1,flag=a[0];
	for(int i=1;i<n;i++){
		if(flag==a[i])l2++;
		else{
			l=max(l,l2);
			l2=1;flag=a[i];
		}
	}
	return l;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=a[n-1]-a[0];i++){
		if(find(i)==-1)continue;
		else{
			j=0;
			while(a[find(i)]==a[find(i)-j]){
				if(m-=i>=0){
					m-=i;
					a[find(i)-j]=a[find(i)+1];
					long long f=f2();
					maxx=max(maxx,f);
					if(maxx==n||m==0){
						cout<<maxx;return 0;
					}
				}
				else{
					long long f=f2();
					maxx=max(maxx,f);
					return 0;
				}
				j++;
			}
		}
	}
	cout<<maxx;
	fclose(stdin);fclose(stdout);
	return 0;}