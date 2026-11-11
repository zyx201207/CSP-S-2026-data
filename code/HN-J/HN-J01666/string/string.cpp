#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	long long num;
	char c;
};
node a[N];
//node ll,lr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*
	6
 1000000000 a
 2000000000 a
 1000000000 a
 2000000000 b
 1000000000 b
 2000000000 b
 aadadnnnnadddd 
3
2 a
2 b
1 c
	*/
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
		//cout<<l<<" "<<r<<" ";
		/*
		ll.a+=a[l].a;
		lr.a+=a[r].a;
		ll.c=a[l].c;
		lr.c=a[r].c;*/
		node ll=a[l],lr=a[r];
		if(ll.num>lr.num){
			if(ll.c!=lr.c){
				ans+=a[r].num;
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}else{
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
		}else{
			if(ll.c!=lr.c){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else{
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			} 
		}
		
	}
	cout<<ans;
	return 0; 
}
