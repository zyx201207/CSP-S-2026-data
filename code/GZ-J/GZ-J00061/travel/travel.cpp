// 准考证号：GZ-J00061  姓名： 孙连友
#include<iostream>
#include<string>
using namespace std;
void solve(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int q=0;
	if(a==c){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			if(b[2]<'D'&&d[2]<'D'){
				printf("1");
				q=1;
				if(b[2]-d[2]==1||b[2]-d[2]==-1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
				return ;
			}
			if(b[2]>='D'&&d[2]>='D'){
				printf("11");
			}else{
				if(q==0){
					printf("00");
				}
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
