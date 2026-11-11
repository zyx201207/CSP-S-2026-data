#include<bits/stdc++.h> 
using namespace std;
int a[100010],b,x,anc[1010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	long long n,m,sum=0;
	cin>>n>>m;
	int mid;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	mid=sum/n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(double(a[i])>=mid){
			x=i;
			b=a[i];
			break;
		}
	}
	int sum2=0;
	for(int i=x;i<=n;i++){
		if(b==a[i]){
			sum2++;
		}
	}
	for(int i=x-1;i>=1;i--){
		if(m-(b-a[i])>=0){
			anc[1]++;
			m-=(b-a[i]);
		}
		else{
			break;
		}
	}
	int q=2;
	if(m!=0){
		for(int i=x+1;i<=n;i++){
			cout<<i<<"\n";
			x++;
			b=a[x];
			for(int i=x-1;i>=1;i++){
				if(b=a[x+1]) break;    
				else{
					if(m-(b-a[i])>=0){
					anc[q]++;
					q++;
					sum2--;
					m-=(b-a[i]);
					}
					else{
					break;
					}
				}
			}
		}
	}
	int ancc=-1;
	for(int i=1;i<=q;i++){
		ancc=max(ancc,anc[i]);
	}
	cout<<sum2+ancc;
	fclose(stdin);
	fclose(stdout);
}
