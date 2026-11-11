#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,sum=1;
struct node{
	int a,cnt=0;
	char s;
	bool f=0;
}csp[N],cspj[N];
int jds(int x){
	if(x>=0) return x;
	else return -x;
}
int str(node x[]){
	int ant=0;
	if(sum%2==0) sum/=2;
	else sum=sum/2+1;
	for(int i=1;i<=sum;i++){
		if(x[i].a==x[sum-i+1].a&&x[i].s==x[sum-i+1].s) continue;
		else if(x[i].a==x[sum-i+1].a&&x[i].s!=x[sum-i+1].s) ant+=x[sum-i+1].s;
		else if(x[i].a!=x[sum-i+1].a&&x[i].s==x[sum-i+1].s){
			ant+=jds(x[i].a-x[sum-i+1].a);
			if(x[i].a>x[sum-i+1].a) x[i+1].a+=jds(x[i].a-x[sum-i+1].a),x[i].a-jds(x[i].a-x[sum-i+1].a);
			if(x[i].a<x[sum-i+1].a) x[sum-i].a+=jds(x[i].a-x[sum-i+1].a),x[sum-i+1].a-jds(x[i].a-x[sum-i+1].a);
		}
		else{
			int pj=x[i].a+x[sum-i+1].a;
			if(pj%2==0){
				pj/=2;
				ant+=min(x[i].a,x[sum-i+1].a);
				ant+=(jds(pj-x[i].a)+jds(pj-x[sum-i+1].a));
			}
			else{
				pj/=2;
				ant+=min(x[i].a,x[sum-i+1].a);
				ant+=(jds(pj-x[i].a)+jds(pj-x[sum-i+1].a));
				x[i+1].a++;
			}
			
		}
	}
	return ant;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>csp[i].a>>csp[i].s;
	for(int i=1;i<n;i++){
		while(i+1<=n&&csp[i].s==csp[i+1].s){
			csp[i].cnt+=csp[i+1].a; 
			csp[i+1].f=1;
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		if(csp[i].f==0){
			if(csp[i].cnt!=0) cspj[sum].a=csp[i].cnt,cspj[sum].s=csp[i].s,sum++;
			if(csp[i].cnt==0) cspj[sum].a=csp[i].a,cspj[sum].s=csp[i].s,sum++;	
		}
	}
	if(sum==1){
		cout<<0;
		return 0;
	}
	cout<<str(cspj);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//2 a     2 b     1 c
