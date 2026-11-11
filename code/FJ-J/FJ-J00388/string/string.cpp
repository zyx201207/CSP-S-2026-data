#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n;

long long cnt=0;

struct Node{
	long long l;
	char x;
};

Node s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].x;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].x==s[r].x){
			if(s[l].l>s[r].l){
				s[l].l-=s[r].l;
				r--;
			}else if(s[l].l<s[r].l){
				s[r].l-=s[l].l;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(s[l].l>s[r].l){
				cnt+=s[r].l;
				s[l].l-=s[r].l;
				r--;
			}else if(s[l].l<s[r].l){
				cnt+=s[l].l;
				s[r].l-=s[l].l;
				l++;
			}else{
				cnt+=s[l].l;
				l++;
				r--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}