#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<char,long long> > a(n+1);
	vector<long long> psum(n+1, 0);
	for(int i = 1;i<=n;i++){
		cin>>a[i].second>>a[i].first;
		psum[i] = psum[i-1] + a[i].second;
	}
	long long ans = 0;
	int lefta = 1, righta = n;
	long long totlen = psum[n]-psum[0];
	long long leftlen = psum[1]-psum[0], rightlen = psum[n]-psum[n-1];
	long long leftpos = 1, rightpos = totlen;
	while(lefta < righta){//重合时就代表同一段 
		if(leftlen>rightlen){
			if(a[lefta].first == a[righta].first){
				righta--;
				leftlen -= rightlen;
				leftpos+=rightlen;
				rightpos -= rightlen;
				rightlen = psum[righta] - psum[righta-1];
			}
			else{
				ans+=rightlen;
				righta--;
				leftlen -= rightlen;
				leftpos+=rightlen;
				rightpos -= rightlen;
				rightlen = psum[righta] - psum[righta-1];
			}
		}
		else if(leftlen<rightlen){
			if(a[lefta].first == a[righta].first){
				lefta++;
				rightlen-=leftlen;
				leftpos+=leftlen;
				rightpos-=leftlen;
				leftlen = psum[lefta]-psum[lefta-1];
			}
			else{
				ans+=leftlen;
				lefta++;
				rightlen-=leftlen;
				leftpos+=leftlen;
				rightpos-=leftlen;
				leftlen = psum[lefta]-psum[lefta-1];
			}
		}
		else{
			if(a[lefta].first == a[righta].first){
				lefta++;
				righta--;
				leftpos+=leftlen;
				rightpos-=rightlen;
				leftlen = psum[lefta]-psum[lefta-1];
				rightlen = psum[righta] - psum[righta-1];
			}
			else{
				ans+=leftlen;
				lefta++;
				righta--;
				leftpos+=leftlen;
				rightpos-=rightlen;
				leftlen = psum[lefta]-psum[lefta-1];
				rightlen = psum[righta] - psum[righta-1];
			}
		}
	}
	cout<<ans;
	return 0;
}
