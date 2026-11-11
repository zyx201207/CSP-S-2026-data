#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll x;
	char ch;
}a[200005];
ll n,len,half,cut;
bool f;
vector<node> v1,v2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ch;
		len+=a[i].x;
	}
	if(len%2!=0) f=1;
	len/=2;
	for(int i=1; ;i++){
		if(half+a[i].x<=len){
			half+=a[i].x;
			v1.push_back({a[i].x,a[i].ch});
		}
		else{
			v1.push_back({len-half,a[i].ch});
			a[i].x-=len-half;
			half+=len-half;
			
			//cout<<half<<' '<<len<<endl;
			if(f&&a[i].x>=1) a[i].x--;
			else if(f) cut++;
			cut+=i;
			break;
		}
	}
	/*
	 如果字符相同，则a[i]减去v1[0]的长度
	*/
	ll tot=cut,ans=0;
	if(a[tot].x<=0) tot++;
	//cout<<tot<<endl;
	while(!v1.empty()){
		node tmp=v1[v1.size()-1];v1.pop_back();
		if(a[tot].ch==tmp.ch){
			//cout<<"1";
			if(a[tot].x>=tmp.x){
				//cout<<"1";
				a[tot].x-=tmp.x;
			}
			else{
				//cout<<"2";
				tmp.x-=a[tot].x;
				v1.push_back({tmp.x,tmp.ch});
				tot++;
			}
		}
		else{
			//cout<<"2";
			if(a[tot].x>=tmp.x){
				//cout<<"1";
				a[tot].x-=tmp.x;
				ans+=tmp.x;
			}
			else{
				//cout<<"2";
				tmp.x-=a[tot].x;
				ans+=a[tot].x;
				v1.push_back({tmp.x,tmp.ch});
				tot++;
			}
		}
		//cout<<tot<<endl;
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
