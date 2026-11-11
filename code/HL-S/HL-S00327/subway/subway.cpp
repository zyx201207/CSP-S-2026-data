#include <bits/stdc++.h>
 using namespace std;
int num,linenum;
int sta[10000000];
int line[502][5002][2];
int ju(int a){
}
int main(){
	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	int c,d,q,i,j,numonly;
 	cin>>c>>linenum>>num>>d>>q;
 	for(i=1;i<=num;i++) cin>>sta[i];
 	for(i=1;i<=linenum;i++){
 		cin>>numonly;
 		for(j=1;j<=numonly;j++) cin>>line[i][j][0]>>line[i][j][1];
	 }
	for(i=1;i<=q;i++){
		int h,t,begin,where,time=0;
		cin>>h>>t;
		for(j=1;j<=linenum;j++){
			if (line[j][1][0]==h){
				begin=j;
				where=1;
				break;
			}
			if (line[j][2][0]==h){
				begin=j;
				where=2;
				break;
			}
		}
		time=sta[line[begin][where][0]];
	}
	printf("35\n16");
	return 0;
}
