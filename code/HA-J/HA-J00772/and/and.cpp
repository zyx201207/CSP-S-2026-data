#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
int a[200100];
vector<int> s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	s.clear();
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s.push_back(i);
	for(int j=30;j>=0;j--){
		vector<int> s1;
		s1.clear();
		for(int t=0;t<=s.size()-1;t++){
			if(a[s[t]]&(1<<j)) s1.push_back(s[t]);
		}
		if(s1.size()>=m){
			s.clear();
			for(int i=0;i<=s1.size()-1;i++){
				s.push_back(s1[i]);
			}
			ans+=(1<<j);
		}
	}
	printf("%d\n",ans);
	return 0;
}
