//GZ-J00238 中央民族大学附属中学贵阳学校  杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
struct st{
	int num;
	char c;
};
long long n,num,cnt,k=0;
st con[200005];
string s;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>a;
		k++;
		if(a==con[k-1].c)k--;
		con[k].num+=num;
		con[k].c=a;
	}
	for(int i=1;i<=(k+1)/2;i++){
		if(k==1){
			cnt=0;
			break;
		}
		if(con[i].c==con[k+1-i].c){
			cnt+=max(con[i].num,con[k+1-i].num)-min(con[i].num,con[k+1-i].num);
		}else{
			cnt+=con[i].num;
		}
	}
	cout<<cnt;
return 0;
}

