//GZ-J00620 ¹ùå°Ðù 
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a(n+1);
vector<bool> b(n+1);
vector<int> c(n+1);
vector<pair<bool,int> > t(m+1);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=1;
			if(t[a[j]].first){
				t[a[j]].first=0;
				for(int k=t[a[j]].second;k<j;k++){
					t[a[k]].first=0;
					b[k]=0;
				}
			}
			else{
				t[a[j]].first=1;
				t[a[j]].second=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]) c[a[j]]++;
		}
		for(int j=1;j<=n;j++) b[j]=0;
	}
	for(int i=1;i<=m;i++){
		printf("%d",c[i]);
	}
	return 0;
}
