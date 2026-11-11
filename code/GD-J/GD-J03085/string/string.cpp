#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
ll n;
struct node{
	ll val;
	char cha;
}a[N];

ll num;
char ch;
ll sum,s[N],mid,midi,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>num>>ch;
		sum+=num;
		s[i]=s[i-1]+num;
		a[i]={num,ch};
	}
	mid=sum/2;
	for(int i=1;i<=n;i++){
		if(mid<=s[i]){
			midi=i;
			break;
		}
	}
	int l=1,r=n;
	while(l<=midi){
		while(a[l].val){
			if(a[l].val>=a[r].val){
				if(a[l].cha!=a[r].cha){
					ans+=a[r].val; 
				}
				a[l].val-=a[r].val;
				a[r].val=0;
				r--;
			}
			else{
				if(a[l].cha!=a[r].cha){
					ans+=a[l].val;
				}
				a[r].val-=a[l].val;
				a[l].val=0;
			}
		}
		l++;
	}
	cout <<ans;
	return 0;
} 
