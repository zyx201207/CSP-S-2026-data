#include<iostream>
#include<stack>
using namespace std;
struct s{
	long long a,l;
	char c;
};
int main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	stack<s> st;
	long long n,a[200005],sum = 0,cnt = 0;
	char c[200005];
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum = sum%2==0?sum/2:sum/2+1;
	long long u = 1;
	for(int i = 1;i<=n;i++,u++){
		if(cnt+a[i]>=sum){
			st.push({sum-cnt,cnt,c[i]});
			a[i] = a[i]-(sum-cnt);
			cnt=sum;
			break;
		}
		cnt+=a[i]; 
		st.push({a[i],cnt,c[i]}); 
	}
	long long ans = 0;
	for(int i = u;i<=n;i++){
		int now = cnt;
		cnt+=a[i];
		while(now!=cnt){
				if(now+st.top().a<=cnt){
					now+=st.top().a;
					if(st.top().c!=c[i])ans+=st.top().a;
					st.pop();
				}else{
					st.top().a-=cnt-now;
					if(st.top().c!=c[i])ans+=cnt-now;
					now=cnt; 
					break;
				}
		}
	}
	cout<<ans;
	return 0;
}
