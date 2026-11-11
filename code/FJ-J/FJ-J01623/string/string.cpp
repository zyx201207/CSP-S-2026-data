#include<bits/stdc++.h>
using namespace std;
#define int long long
struct tx{
	int s;
	char c;
}a[200005];
vector<tx> b1;
vector<tx> b2;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		sum+=a[i].s;
	}
	int o=sum/2;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i].s;
		if(sum1==o){
			b1.push_back({a[i].s,a[i].c});
			break;
		}else if(sum1<o){
			b1.push_back({a[i].s,a[i].c});
		}else{
			b1.push_back({a[i].s-sum1+o,a[i].c});
			break;
		}
	}
	for(int i=n;i>=1;i--){
		sum2+=a[i].s;
		if(sum2==o){
			b2.push_back({a[i].s,a[i].c});
			break;
		}else if(sum2<o){
			b2.push_back({a[i].s,a[i].c});
		}else{
			b2.push_back({a[i].s-sum2+o,a[i].c});
			break;
		}
	}
	/*for(int i=0;i<b1.size();i++){
		cout<<b1[i].s<<" ";
	}
	cout<<endl;
	for(int i=0;i<b2.size();i++){
		cout<<b2[i].s<<" ";
	}
	cout<<endl;*/
	int ans=0;
	for(int i=0,j=0;i<b1.size() && j<b2.size();){
		if(b1[i].s==b2[j].s){
			if(b1[i].c!=b2[j].c){
				ans+=b1[i].s;
			}
			i++;
			j++;
		}else if(b1[i].s>b2[j].s){
			b1[i].s-=b2[j].s;
			if(b1[i].c!=b2[j].c){
				ans+=b2[j].s;
			}
			j++;
		}else{
			b2[j].s-=b1[i].s;
			if(b1[i].c!=b2[j].c){
				ans+=b1[i].s;
			}
			i++;
		}
	}
	cout<<ans;
	return 0;
}
