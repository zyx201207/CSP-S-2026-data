//GZ-J00319 卓然 贵阳中天中学 

//开long long！！！！！
 
#include<bits/stdc++.h>
using namespace std;
pair<long long,char> a[200005];
long long n,i,j,ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int q=1;q<=n;q++){
		cin>>a[q].first>>a[q].second;
	}
	i=1,j=n;
	while(i<j){
		if(a[i].second!=a[j].second){
			ans+=min(a[i].first,a[j].first);
		}
		if(a[i].first>a[j].first){
			a[i].first-=a[j].first;
			j--;
			continue;
		}else if(a[i].first<a[j].first){
			a[j].first-=a[i].first;
			i++;
			continue;
		}else if(a[i].first==a[j].first){
			i++,j--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
