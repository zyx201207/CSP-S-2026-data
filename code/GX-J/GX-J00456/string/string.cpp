#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum = 0;
const int maxn = 2e5 + 10;
ll n;
struct node {
	char op;
	ll p;
};
node a[maxn];
node s1[maxn];
node s2[maxn];
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].p>>a[i].op;
		sum += a[i].p;
	}
	// divide_s1
	ll sum_s1 = 0,count = 0,stop = 0,last_diff = 0;
	for(int i = 1;i<=n;++i){
		//cout<<sum_s1+a[i].p<<endl;
		if(sum_s1 == sum/2) {
			stop = i - 1;
			break;
		}
		else if(sum_s1+a[i].p<sum/2){
			sum_s1+=a[i].p;
			count++;
			s1[count].p = a[i].p;
			s1[count].op = a[i].op;
		}
		else if(sum_s1<sum/2&&sum_s1+a[i].p>=sum/2){
			ll diff = sum/2 - sum_s1;
			count++;
			sum_s1 += diff;
			s1[count].p = diff;
			s1[count].op = a[i].op; 
			last_diff = diff;
		}
	}
	//for(int i=1;i<=count;++i){cout<<s1[i].p<<" "<<s1[i].op<<endl;}
	//divide_s2
	if(a[stop].p-last_diff<0){
		a[++stop].p -= last_diff;
	}
	else   a[stop].p -= last_diff; 
	if(a[stop].p-sum%2<0){
		a[++stop].p -= sum%2;
	}
	else   a[stop].p -= sum%2; 
	ll sum_s2 = 0;
	ll count_s1 = 0;
	for(int i = stop;i<=n;++i){
		if(sum_s2 == sum/2) {
			break;
		}
		else if(sum_s2+a[i].p<sum/2){
			sum_s2+=a[i].p;
			count_s1++;
			s2[count_s1].p = a[i].p;
			s2[count_s1].op = a[i].op;
		}
		else if(sum_s2<sum/2&&sum_s2+a[i].p>=sum/2){
			ll diff = sum/2 - sum_s2;
			count_s1++;
			sum_s2 += diff;
			s2[count_s1].p = diff;
			s2[count_s1].op = a[i].op; 
		}	
	}
	//cout<<sum/2<<" "<<count<<" "<<sum_s1<<" "<<endl;
	//for(int i=1;i<=count;++i){cout<<s2[i].p<<" "<<s2[i].op<<endl;}
	
	//ans
	int ans = 0;
	if(count<=count_s1){
		swap(count,count_s1);
	}
		int idx = count_s1;
		for(int i=1;i<=count;++i){
			int difff = 0;
			if(s1[i].p<=s2[idx].p&&s1[i].op == s2[i].op){
				s2[idx].p -= s1[i].p;
				if(s2[i].p<0) difff = s2[i].p;
			}
			else if(s1[i].op!=s2[idx].op){
				ans+=s1[i].p;
				s2[idx].p -= s1[i].p;
				if(s2[i].p<0) difff = s2[i].p;
			}
			if(s2[i].p<=0) {
				idx--;
				s2[i].p+=difff;
			}
		}
		cout<<ans;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N = 1;
	while(N--) solve();
	return 0;
}
