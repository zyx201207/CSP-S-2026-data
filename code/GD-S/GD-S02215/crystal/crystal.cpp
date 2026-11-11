#include<bits/stdc++.h>
using namespace std;
int n,m;
int nn[100000005];int mmmx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    cin>>nn[i];
	int sm=0;sort(nn,nn+n);
	for(int i=0;i<n;i++){
		int mm=m,cnttt=1;
		for(int j=i-1;j>=sm;j--){
			if(nn[i]-nn[j]<=mm){
				cnttt++;
				mm-=nn[i]-nn[j];
			}
			else{
				sm=j+1;
			}
		}
		mmmx=max(mmmx,cnttt);
	}
	cout<<mmmx;
}
/*


我是GD-J02246
luogu uid2103085(还是3058 忘了)
昵称叫cqy666666
过来果然被炸鱼了U_U ): O_O
我J组题目名应该没写错吧 





















今天是平安夜，因为成绩今天出不了 



















下周就不一定了 
















































我就这题会做一点 
*/
