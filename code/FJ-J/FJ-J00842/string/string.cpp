#include <bits/stdc++.h>
using namespace std;
const int maxn=1e9+100;
char c[maxn];
int n;
long long a[maxn],sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	vector<string>s;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<=n;i++){
	    for (int j=0;j<=a[i];j++){
	    	s.push()=s[i]; 
	    }
    }
    for(int m=0;m<=((int)s.size)/2;m++){
    	if(s[m]!=s[(int)s.size-m]){
    	s[m]=s[(int)s.size-m];
    	sum++;
        }
	}
	cout<<sum;
	return 0;
}
