#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cnt[300005];
bool d[300005];
vector<long long>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		memset(d,0,sizeof(d));
		for(int j=i;j<n;j++){
			if(j==0){
			//	cout<<"{"; 
				s.push_back(a[j]);
				d[a[j]]=1;
				for(int k=0;k<s.size();k++){					
					cnt[s[k]]++;
				//	cout<<"("<<cnt[s[k]]<<" ="<<s[k]<<") ";
				}
			//	cout<<"}"; 
				continue;
			}
			else{
				if(!d[a[j]]){
				//	cout<<"{"; 
					s.push_back(a[j]);
					d[a[j]]=1;
					for(int k=0;k<s.size();k++){						
						cnt[s[k]]++;
				//		cout<<"("<<cnt[s[k]]<<" +"<<s[k]<<") ";
					}
				///	cout<<"}";
					continue;
				}
				else{
				//	cout<<"{"; 
					d[a[j]]=0;
					long long id=lower_bound(s.begin(),s.end(),a[j])-s.begin();					
					s.erase(s.begin()+id,s.end());
					s.push_back(a[j]);
					for(int k=0;k<s.size();k++){					
						cnt[s[k]]++;
						//cout<<"("<<cnt[s[k]]<<" -"<<s[k]<<") ";
					}
				//	cout<<"}"; 
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
