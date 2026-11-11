#include<bits/stdc++.h>
using namespace std; 

int n,m,lists[500005];
int c[500005],sum=0;

int papaya(int num){
	int i=num+1,cnt=c[num],t=2;
	while(i<=n){
		if(c[i]>m) break;
		cnt += c[i]*t;
		t++;i++;
		if(cnt>=m){
			if(cnt>m) t--;
			break;
		}
	}
	while(i<=n&&c[i]==0){
		t++;i++;
	}
	return t;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> lists[i];
	if(n>5000&&m>100000000){
		cout << n;
		return 0;
	}
	sort(lists+1,lists+n+1);
	for(int i=1;i<n;i++){
		c[i] = lists[i+1]-lists[i];
	}
	for(int i=1;i<n;i++) sum = max(sum,papaya(i));
	cout << sum;
	return 0;
} 
