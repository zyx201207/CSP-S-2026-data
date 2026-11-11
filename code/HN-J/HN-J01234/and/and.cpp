#include <iostream>
using namespace std;
int n,m,a,b[2000][2000],c[2000],s,q[100],g,p[10];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	for(int i=0;i<100;i++) q[i]=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		int k=0;
		while(1){
			b[i][k]=a%2;
			a=a/2;
			k++;
			if(a==1){
				b[i][k]=a;
				break;
			}
			else if(a==0) break;
		}
	}
	for(int i=0;i<n;i++){
		int k=100;
		while(1){
			if(b[i][k]==1){
				if(s<k+1){
					s=k+1;
				}
				break;
			}
			k--;
		}
	}
	for(int i=s-1;i>=0;i--){
		for(int j=0;j<n;j++){
			if(b[i][j]!=1){
				q[j]=0;
			}
			g=0;
			for(int j=0;j<n;j++){
				g+=q[j];
			}
			if(g<=m) break;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++) cout<<q[i]<<" ";
//	int k=0;
//	for(int i=0;i<n;i++){
//		if(q[i]==1){
//			p[k]=i;
//			k++;
//		}
//	}
//	for(int j=0;j<=s-1;j++){
//		if(b[q[0]][j]&&b[q[1]][j]) c[j]=1;
//		else c[j]=0;
//	}
//	for(int i=2;i<m;i++){
//		for(int j=0;j<=s-1;j++){
//			if(c[j]&&b[q[i]][j]) c[j]=1;
//			else c[j]=0;
//		}
//	}
//	for(int j=0;j<=s-1;j++){
//		cout<<c[j];
//	}
	return 0;
} 
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7
*/
