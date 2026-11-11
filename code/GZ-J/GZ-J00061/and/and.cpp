// 准考证号：GZ-J00061  姓名： 孙连友
#include<iostream> 
#include<string>
using namespace std;
	int s[200000]； 
void solve(){
	int n,m;
	cin>>n>>m;
	int max=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(max<s[i]^s[j]){
				max=s[i]^s[j];
			}
		}
	}
	printf("%d",max);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
