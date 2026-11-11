#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long cnt;
	char c[N];
	string s;
	long long sl[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sl[i]>>c[i];
	}
	for(int i=1,j=n;i<n/2+1&&j>=n/2+1;){
		if(c[i]!=c[j]){
			if(sl[i]>sl[j]){
				cnt+=sl[j];
				sl[i]-=sl[j];
				j--;
			}else if(sl[j]>sl[i]){
				cnt+=sl[i];
				sl[j]-=sl[i];
				i++;
			}else{
				cnt+=sl[i];
				i++;
				j--; 
			}
		}else{
			i++;
			j--;
		}
	}
	cout<<cnt;
	
	return 0; 
} 
