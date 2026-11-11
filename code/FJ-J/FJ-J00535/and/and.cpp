#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000],max1=-1,b[20000],t=0,s[20000][20000],s2[20000],e[20000],s1[20000];
void and_m(int x){
	for(int i=0;i<n;i++){
		if(b[i]!=0){
			continue;
		}
		int v=t;
		t=0;
		int q=t,j=0;
		while(q!=0){
			s2[j]+=q%2;
			q/=2;
			if(q==0){
				break;
			} 
			j++;
		}
		if(j<s1[i]){
			for(int x=j-1;x>=0;x++){
				if(s[i][x]==s2[x]){
					e[x]=1;
				}else{
					e[x]=0;
				}
			}
			for(int x=j-1;x>=0;x++){
				t+=e[x];
				t*=2;
			}
			t/=2;
			cout<<t;
		}else{
			for(int x=s1[i]-1;x>=0;x++){
				if(s[i][x]==s2[x]){
					e[x]=1;
				}else{
					e[x]=0;
				}
			}
			for(int x=s1[i]-1;x>=0;x++){
				t+=e[x];
				t*=2;
			}
			t/=2;
			cout<<t;
		}
		if(x==m){
			if(t>=max1){
				max1=t;
			}
			t=v;
			cout<<max1<<endl;
			return;
		}
		b[i]==1;
		and_m(x++);
		cout<<t<<endl;
		t=v;
		b[i]==0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int j=0,k=a[i];
		while(k!=0){
			s[i][j]+=k%2;
			k/=2;
			j++;
		}
		s1[i]=j;
	}
//	and_m(1);
	cout<<n;
	return 0;
} 
