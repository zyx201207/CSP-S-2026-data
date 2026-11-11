//GZ-J00637,濮铭希,贵阳市第二十九中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans,l[N],r[N];
char c[N];
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long k=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=k;
		k+=a[i];
		r[i]=k-1;
	}
	k--;
	long long cnt,cnt2;
	cnt=(k/2)+1;
	long long left,right=cnt+1;
	if(k%2==0){
		cnt2=k/2;
		char m,m2;
		for(int i=1;i<=n;i++){
			if(cnt>=l[i]&&cnt<=r[i]){
				m=c[i];
			}
			if(cnt2>=l[i]&&cnt2<=r[i]){
				m2=c[i];	
			}
		}
		if(m!=m2){
			ans++;
		}
		left=cnt2-1;	
	}
	else{
		left=cnt-1;
	}
	while(left>=1&&right<=k){
		char d,d2;
		for(int i=1;i<=n;i++){
			if(left>=l[i]&&left<=r[i]){
				d=c[i];
				continue;
			}
			if(right>=l[i]&&right<=r[i]){
				d2=c[i];
				continue;
			}	
		}
		if(d!=d2){
			ans++;
		}
		left--;
		right++;	
	}
	cout<<ans;
	return 0;
}
