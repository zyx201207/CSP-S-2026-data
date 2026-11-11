//GZ-J00619 北京师范大学贵阳附属中学 杨然
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001000;
long long n,m,a[maxn],ans[maxn],ma = -1,c;
vector<int> v;
void card(int x){
	for(int i = x;i<n;i++){
			for(int j = 0;j<v.size();j++){
			if(a[i] == v[j]){
				v.erase(v.begin() + j,v.end());
				break;
			}
		}	
		v.push_back(a[i]);		
	}
}
int main()
{
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<n;i++){
	   scanf("%lld",&a[i]);
	   if(a[i] >= ma)ma = a[i];
	}
	for(int i = 0;i<n;i++){
		card(c++);	
		for(int j = 0;j<v.size();j++)ans[v[j]]++;
		v.erase(v.begin(),v.end());
	}
	for(int i = 1;i<=ma;i++)
	if(ans[i]!=0)
	printf("%d ",ans[i]);
	return 0;
}
