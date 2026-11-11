//GZ-J00183，乔浩宇，安顺市实验学校
#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	long long a[1000000000005];
	string c[10000000000005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int j=1;j<=n;j++){
		if(c[j]==c[n-j+1]){
			cnt+=0;
		}
		else if(c[j]==c[n-j+1]){
			c[j]=c[n-j-1];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
