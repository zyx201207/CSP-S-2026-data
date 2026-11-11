#include<bits/stdc++.h>
using namespace std;
int n;
long long weight=0;
struct node{
	string a;
	int x;
}b[200005];
node c[200005];//左 
node d[200005];//右 
int ci,di;
long long ans=0;
void qu(){
	
	int i=0,iweight=0;
	int k=1;
	while(iweight<=weight/2){
		i+=1;
		if(iweight+b[i].x<=weight/2){
			c[k].a=b[i].a;
			c[k].x=b[i].x;
			iweight+=b[i].x;
			k+=1; 
		}
		else{
			c[k].a=b[i].a;
			c[k].x=weight/2-iweight;
			iweight+=b[i].x;
			k+=1;
		}
	}
	ci=k-1;
	i=n+1,iweight=0;
	k=1;
	while(iweight<=weight/2){
		i-=1;
		if(iweight+b[i].x<=weight/2){
			d[k].a=b[i].a;
			d[k].x=b[i].x;
			iweight+=b[i].x;
			k+=1; 
		}
		else{
			d[k].a=b[i].a;
			d[k].x=weight/2-iweight;
			iweight+=b[i].x;
			k+=1;
		}
	}
	di=k-1;
//	cout<<1<<endl;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","l",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].a;
		weight+=b[i].x;
	}
//	cout<<1<<endl;
	qu();
	int l=1,r=1;
	int i=0;
	int llong=c[l].x,rlong=d[r].x;
	while(l<=ci && r<=di){
		i++;
		if(i>n){
			break;
		}
		if(c[l].a!=d[r].a){
			if(c[l].x>d[r].x){
				ans+=d[r].x;
				r++;
			}
			else if(c[l].x<d[r].x){
				ans+=c[l].x;
				l++;
			}
			else{
				ans+=c[l].x;
				l++;
				r++;
			}
		}	
	}
	cout<<ans;
	return 0;
}
//检查从1-weight/2与后面的差别 
//aaaabb
// 1    //指针
//判断指针之前是否相等 
//aaabbcc aabbcbb 14
//
//2+1+
