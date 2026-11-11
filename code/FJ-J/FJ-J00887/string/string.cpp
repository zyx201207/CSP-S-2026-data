#include<bits/stdc++.h>
using namespace std;
//I Love CCF So Much!
const int N=2e5+500;
int n;
int ans=0;
int a[N];
char c[N];
bool bf=1;
string hui(string s){
	for(int i=0;i<s.size()/2;i++){
		swap(s[i],s[s.size()-1-i]);
	}
	return s;
}
void solve1(){
	
	if(a[0]==a[1]){
		cout<<a[0];
		return ;
	}else{
		cout<<min(a[0],a[1]);
	}
}
void solve2(){
	string s;
	for(int i=0;i<n;i++){
		s+=c[i];
	}
	int cnt=0;
	string s2=hui(s);
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
void solve3(){
	int ans=0;
	int p=0,q=n-1;
	while(p<q){
		if(a[p]==a[q]){
			if(c[p]!=c[q]){
				ans+=a[p];
			}
			p++;
			q--;
		}else if(a[p]>a[q]){
			if(c[p]==c[q]){
				a[p]-=a[q];
				a[q]=0;
			}else{
				ans+=a[p]-a[q];
				a[p]-=a[q];
				a[q]=0;
			}
			q--;
		}else{
			if(c[p]==c[q]){
				a[q]-=a[p];
				a[p]=0;
			}else{
				ans+=a[q]-a[p];
				a[q]-=a[p];
				a[p]=0;
			}
			p++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
		if(i!=0&&c[i]!=c[i-1])bf=0;
	}
	if(bf){
		cout<<0;
		return 0;
	}
	if(n<=2){
		solve1();
	}else if(ans==n){
		solve2();
	}else{
		solve3();
	}
	return 0;
}
