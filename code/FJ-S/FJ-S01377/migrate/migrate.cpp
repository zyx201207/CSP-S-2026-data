#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;bool bj=0;char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')bj=1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj)x=-x;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,t,n;
long long d,x[2000006],cd[2000006],jl[2000006];
queue<pair<int,int>> q;
void xz(int h){
	q.push({h,0});cd[h]=0;
	while(!q.empty()){
		int ls1=q.front().first,ls2=q.front().second;q.pop();
		for(int i=ls1+1;i<=n;i++){
			if(x[i]-x[ls1]<=d){
				if(cd[i]==0){
					cd[i]=ls2+1;jl[i]=1;
					q.push({i,cd[i]});
				}else{
					if(ls2+1<cd[i]){
						cd[i]=ls2+1;
						q.push({i,cd[i]});
						jl[i]=1;
					}else if(ls2+1==cd[i]){
						jl[i]++;
					}else{
						q.push({i,ls2+1});
					}
				}
			}else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--){
		read(n),read(d);int sum=0;
		for(int i=1;i<=n;i++)read(x[i]);
		for(int i=1;i<=n;i++){
			xz(i);
			for(int j=i;j<=n;j++){
				if(jl[i]==2)sum++;
				jl[i]=0;cd[i]=0;
			}
		}
//		int sum=0;
//		for(int i=1;i<=n;i++){
//			if(jl[i]==2)sum++;
//			cout<<jl[i]<<" "<<cd[i]<<"\n";
//			jl[i]=0;cd[i]=0;
//		}
//		cout<<"\n";
		write(sum-1);
		cout<<"\n";
	}
	return 0;
}
