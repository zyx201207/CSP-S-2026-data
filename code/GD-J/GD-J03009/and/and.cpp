#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000010];
int bbb(int p,int q){
	string pp,qq;
	while(p>0){
		pp+=p%2;
		p/=2;
	}
	while(q>0){
		qq+=q%2;
		q/=2;
	}string pq;
	for(int i=0;i<max(pp.size(),qq.size());i++){
		if(pp[i]==1&&qq[i]==1){
			pq+="1";
		}else{
			pq+="0";
		}
	}int pqpq;
	for(int i=0;i<pq.size();i++){
		pqpq+=pq[i]==1*pow(2,i);
	}
	return pqpq;
}int aaa(int p,int q){
	int pp;
	int qq;
	if(p>b){
		return c[q];
	}
	for(int i=q+1;i<a-b+q;i++){
		qq=aaa(p+1,i);
		pp=max(pp,qq&c[i]);
		
	}//cout<<pp<<endl;
	return pp;
}
int main(){
cin>>a>>b;
for(int i=0;i<a;i++){
	cin>>c[i];
}
cout<<aaa(0,0);
} /*4 2
3 15 12 12 

5 3
31 3 1 15 7*/
