#include<bits/stdc++.h>
using namespace std;
int num[200005];
char x[200005];
int main(){
	freopen(string.in,"stdin","r");
	freopen(string.out,"stdout","w");
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>num[i]>>x[i];
		num[i] = num[i]+num[i-1];
	}
	long long L = num[n],cnt = 0;
	long long l = 1,r = num[1],k = 1;
	
	while(r<=(L+1)/2){
		long long nl = L+1-l;//需要比较的区间 
		long long nr = L+1-r;
		long long fl = lower_bound(num+1,num+n+1,nl)-num;
		long long fr = lower_bound(num+1,num+n+1,nr)-num;
		long long kl = nr;
		for(int i = fr;i<=fl;i++){
			if(x[i]!=x[k]){
				cnt+=num[i]-kl+1;
			}
			kl = num[i]+1;
		}
		k++;
		l = r+1;
		r = num[k];
	}
	cout<<cnt;
	return 0;
}
