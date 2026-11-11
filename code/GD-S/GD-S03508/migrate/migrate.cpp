#include<iostream>
using namespace std;
const int maxn=2e6+10;
int c , t , n , d;
long long A[maxn] , B[maxn] , ans;
int Cnt[5010][5010] ,  C[5010][5010];
bool check(){
	for(int i=3;i <= n;i++){
		if(B[i]!=B[i-1])return false;
	}
	return true;
}
void func1(){
	for(int i=1;i <= n;i++){
		for(int j=i+1;j <= n;j++){
			if(A[j]-A[i]<=d){
				Cnt[i][j]=C[i][j]=1;
			}
		}
	}
	for(int i=1;i <= n;i++){
		for(int j=i+1;j <= n;j++){
			for(int k=i+1;k < j;k++){
				if(C[i][j]==0||C[i][j]>C[i][k]+C[k][j]){
					C[i][j]=C[i][k]+C[k][j];Cnt[i][j]=1;
				}else if(C[i][j]==C[i][k]+C[k][j]){
					Cnt[i][j]++;
				}
			}
			ans+=(Cnt[i][j]==2);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>> c >> t;
	while(t--){
		cin>> n >> d;
		for(int i=1;i <= n;i++){
			cin>> A[i];
			B[i]=A[i]-A[i-1];
		}
		if(A[n]-A[1]<=d){
			cout<<"0\n";continue;
		}
		if(check()){
			ans=((d/B[n])<<1)-1;
			cout<< ((d<(B[n]<<1)||n<=ans)?0:n-ans) <<'\n';
			continue;
		}
		if(n<=5000){
			func1();cout<< ans <<'\n';
			continue;
		}
		cout<<"0\n";
	}
    return 0;
}
