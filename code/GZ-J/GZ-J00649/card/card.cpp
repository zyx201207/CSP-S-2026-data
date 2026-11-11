//GZ-J00649КывужабЇ ЭѕГЏюч 
#include<bits/stdc++.h> 
using namespace std;
long long n,m,sum;
long long a[100005],s[1000005],b[100005];
int qc(long long x,long long i,long long j){
	for(i;i<j;i++){
		if(b[i]==x){
			return i;
		}
	}
	return j;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			b[100005]={};
			for(int j=i;j<=n;j++){
				b[j]=a[j];
				sum++;
				long long c=qc(b[j],i,j);
				for(int k=c;k<j;k++){
					b[k]=0;
				}
				sum-=sum-j+1;
			}
		for(int j=i;j<=n;j++){
			if(b[j]!=0){
				s[b[j]]++;
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}	
