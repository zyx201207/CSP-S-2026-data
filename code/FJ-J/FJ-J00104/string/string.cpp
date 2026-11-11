#include <bits/stdc++.h> 
using namespace std;
int n;
long long m[200005];
string s[200005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>m[i]>>s[i];
	}
	int l=1,r=n;
	while (l<r){
		if (s[l]!=s[r]){
			if (m[l]<m[r]){
				cnt+=m[l];
				m[r]-=m[l];
				m[l]=0;
				l++;
			}
			else if(m[l]>m[r]){
				cnt+=m[r];
				m[l]-=m[r];
				m[r]=0;
				r--;
			}else{
				cnt+=m[l];
				m[l]=0;
				m[r]=0;
				l++;
				r--;
			}
		}else{
			if (m[l]<m[r]){
				m[r]-=m[l];
				m[l]=0;
				l++;
			}else if(m[l]>m[r]){
				m[l]-=m[r];
				m[r]=0;
				r--;
			}else{
				m[l]=0;
				m[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
}
