//GZ-J00697 李昂泽 贵州师范大学附属中学
#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
char a[1000005];
char b[1000005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int cn=0;
	int n;
	cin>>n;
	int d=1;
    for(int i=1;i<=n;i++){
    	cin>>s[i]>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			b[d]=a[i];
			d++;
			cn++;
		}
	}
	long long ji=0;
	int t=cn/2;
	for(int i=1;i<=t;i++){
		for(int j=cn;j>=t;j--){
			if(b[i]!=b[j]) ji++;
		}
	}
	cout<<ji;
    return 0;
}


