//李昊燃 华东师范附属贵阳学校 GZ-J 00234
#include<bits/stdc++.h>
using namespace std;
long long cnt1,cnt2;
long long a[500005],b[500005],cnt[500005];
bool v[500005];
long long x,m,n,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=i;
		for(int j=i;j<=n;j++){
			b[s]=a[j];s++;
			if(v[a[j]]==0) v[a[j]]=1;
			else{//cout<<i<<" "<<s-1<<" "<<j<<" "<<a[j]<<"\n";
				v[b[s-1]]=0;
				b[s-1]=0;
				s--;
				for(int g=s-1;g>=i;g--){
					//cout<<b[g]<<" ";
					
					if(b[g]!=a[j]){
						s--;v[b[g]]=0;
						b[g]=0;
						
					}
					else if(b[g]==a[j]){
						v[b[g]]=1;
						break;
					}
				}//cout<<"\n";
			}
		}
		for(int j=i;j<=s;j++){
			cnt[b[j]]++; 
			//cout<<b[j]<<" ";
			b[j]=0;
		}for(int j=1;j<=n;j++) v[a[j]]=0;
		//cout<<v[1]<<"\n";
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
