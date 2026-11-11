#include<bits/stdc++.h>
using namespace std;
coast int N = 1e5+10;
int n;
int a[N];
char c[N];
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","W",stdout);
	scanf("%d",&n);
	for(int i = 0;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	long long cnt = 0,dead = 0,hou = 0;
	int i = 1;
	while(i<=n){
		int k = n+1-i-hou;
		long long  d = min(a[i],a[k]);
		if(c[i] == c[k]{
			a[i]-=d;
			a[k]-=d;
			}else{
			cnt += d;
			a[i]-=d;
			a[k]-=d;
			}
			if(a[i] ==0){
				i++;
				dead++;
				}
			if(a[k] ==0){
				k--;
				dead++;
				hou++;
				}
			if(dead ==n-1||dead == n){
				break;
			}
		}
			

		printf("%lld",cnt);
		return 0;
	}
