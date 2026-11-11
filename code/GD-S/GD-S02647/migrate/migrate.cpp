#include<bits/stdc++.h>>
using namespace std;
struct sss{
	int xy;
	int th;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	short int c;
	int t,N;
	long long d;
	cin>>c>>t;
	int cnt=0;
	for(int i=1;i<=t;i++){
		cin>>N>>d;
		sss kk[N+5];
		for(int j=1;j<=N;j++){
		cin>>kk[j].xy;
		kk[j].th=j;
		}
		int countend[N+3];
		int countx=-1;
		for(int j=1;j<N;j++){
			
			if(kk[j+1].xy-kk[j].xy>d){
			countx++;
			countend[countx]=j;
				
			}  
		}//记录无法联通下一个岛的岛// 
		for(int j=1;j<countx;j++){
			if(countend[j+1]-countend[j]>3) {
				if(kk[countend[j]].xy-kk[countend[j-1]].xy>=2*d){
					cnt+=countend[j]-countend[j-1];
				}
			} 
		}
	}
	cout <<cnt;
	
	return 0;
} 
