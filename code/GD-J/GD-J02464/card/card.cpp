#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200010];
long long top;
long long hp[200010];
long long s[200010];
long long cnt[200010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(hp[a[j]]){
				for(int k=hp[a[j]]+1;k<=top;k++){
					hp[s[k]]=0;
					s[k]=0;
				}
				top=hp[a[j]]-1;
				hp[a[j]]=++top;
			}
			else{
				s[++top]=a[j];
				hp[a[j]]=top;
			}
		}
		for(int j=1;j<=top;j++) cnt[s[j]]++,hp[s[j]]=0,s[j]=0;
		top=0;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
