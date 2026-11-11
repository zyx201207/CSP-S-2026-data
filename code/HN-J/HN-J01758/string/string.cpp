#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct node{
	string s;
};node x[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    long long L=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
	    cin>>a[i]>>x[i].s;
	    L+=a[i];
	}
	long long ans=0;
	int l=1, r=n;
	int s1=a[1], s2=a[n];
	for(int i=1;i<=L/2;i++){
		if(x[l].s!=x[r].s)ans++;
		s1--;
		s2--;
		if(s1==0){
			l++;
			s1=a[l];
		}
		if(s2==0){
			r--;
			s2=a[r];
		}
	}
	cout<<ans;
	return 0;
}

