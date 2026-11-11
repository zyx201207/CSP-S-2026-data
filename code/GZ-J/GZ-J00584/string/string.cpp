//GZ-J00584，盛诗尧，贵阳市清华中学 
#include<bits/stdc++.h>
using namespace std;
long long js=0,js1=js,ans=0;
struct s{
	int num;
	string name;
}a[100005];
string na;
bool isSmilar;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>js;
	js1=js-1;
	cin>>a[js1].num>>a[js1].name;
	na=a[1].name;
	while(js1--){
		cin>>a[js1].num>>a[js1].name;
		if(a[js1].name!=na){
			isSmilar=1;
		}
	}
	if(isSmilar==0){
		cout<<0;
		return 0;
	}
	js1=(js%2==0?js/2:js/2+1);
	int i=0; 
	while(js>js1){
		if(a[i].name!=a[js-1].name){
			ans+=a[js-1].num;
			
		}
		js--;
		i++;
	}
	cout<<ans;
	return 0;
}
