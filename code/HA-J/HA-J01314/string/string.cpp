#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll p1,p2,sum,s1,s2,ans;
pair<ll,char> a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;char c;
		cin>>tmp>>c;
		a[i]=make_pair(tmp,c);
		sum+=tmp;
	}
	p1=1,p2=n;
	while(s1<=sum/2||s2<=sum/2){
		if(s1<s2){
			if(a[p1].first>=sum/2-s1+1&&a[p1].second!=a[p2+1].second){
				ans+=min(sum/2-s1+1,s2-s1);
			}else if(a[p1].second!=a[p2+1].second){
				ans+=min(a[p1].first,s2-s1);
			}
			s1+=min(sum/2-s1+1,a[p1].first);
			p1++;
		}else if(s2<s1){
			if(a[p2].first>=sum/2-s2+1&&a[p1-1].second!=a[p2].second){
				ans+=min(s1-s2,sum/2-s2+1);
			}else if(a[p2].second!=a[p1-1].second){
				ans+=min(a[p2].first,s1-s2);
			}
			s2+=min(a[p2].first,sum/2-s2+1);
			p2--;
		}else{
			s1+=min(a[p1].first,sum/2-s1+1);
			p1++;
		}
		//cout<<p1<<" "<<p2<<" "<<s1<<" "<<s2<<" "<<ans<<"\n";
	}
	cout<<ans-(sum+1)%2;
	return 0;
}

