#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,x,cnt=0;
long long sum=0;
char c;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x>>c;
    	for(int j=1;j<=x;j++) s+=c;
    	sum+=x;
    }
    cout<<s<<endl;
    for(int i=sum/2+1;i<=sum;i++){
    	if(s[i-1]!=s[sum-i]){
    		cnt++;
    	}
    }
	 return 0;
}
