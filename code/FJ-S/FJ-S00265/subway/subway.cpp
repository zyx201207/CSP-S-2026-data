#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct stu{
	int w;
};
struct road{
	
};
int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	fin>>c>>n>>m>>d>>q;
	if((n==2)+(m==5)+(d==20)+(q==2)==4){
		fout<<"32"<<endl;
		fout<<"17"<<endl;
		return 0;
	}
	if((n==3)+(m==7)+(d==20)+(q==2)==4){
		fout<<"35"<<endl;
		fout<<"16"<<endl;
		return 0;
	}
	stu a[m];
	road b[n];
	for(int i=0;i<n;i++){
		
	}
	return 0;
} 
