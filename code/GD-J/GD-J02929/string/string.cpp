#include <bits/stdc++.h>
using namespace std;
int n,p;
long long t,sum,cnt;
long long a[26][200005];
long long s[200005];
string ss;
char c; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> t;
		cin >> ss;
		a[ss[0]-'a'][i]=sum+1;
		sum+=t;
		s[i]=sum;
	}
	for (int i=0;i<=25;i++){
		int l=1;
		int r=n;
		while (l<=r){
			while(a[i][l]==0&&l<=r)l++;
			while(a[i][r]==0&&r>=l)r--;
			
			if (l>r)break;
			if (l==r){
				cnt+=max(0*1ll,(min(s[l],sum-a[i][l]+1)-max(a[i][l],sum-s[l]+1)+1)/2);
				break;
			}
			if (s[l]<sum-s[r]+1){
				a[i][l]=0;
				l++;
				continue;
			}
			if (a[i][l]>sum-a[i][r]+1){
				a[i][r]=0;
				r--;
				continue;
			}
			long long ax=a[i][l];
			long long ay=s[l];
			long long bx=sum+1-s[r];
			long long by=sum+1-a[i][r];
			if (bx>ay){
				a[i][l]=0;
				continue;
			}
			if (ax>by){
				a[i][r]=0;
				continue;
			}
			ax=max(ax,bx);
			bx=ax;
			cnt+=1ll*(min(ay,by)-ax+1);
			if (ay<by){
				a[i][l]=0;
				l++;
				s[r]=sum-ay+1;
			}
			if (by<ay){
				a[i][r]=0;
				r--;
				a[i][l]=by+1;
			}
			if (by==ay){
				a[i][l]=0;
				a[i][r]=0;
			}
		}
	}
	cout << sum/2-cnt;
	return 0;
} 
