#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
int a[N],s[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	} 
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int o=i;o<n;o++){
			a[b[o]]++;
			if(a[b[o]]>1){
				a[b[o]]--;
				for(int p=o-1;p>=i;p--){
					if(b[p]==b[o]){
						for(int l=p+1;l<o;l++){
							a[b[l]]--;
						}
						break;
					}
					
				}
			}
		}
		for(int o=1;o<=m;o++){
			s[o]+=a[o];
			a[o]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
