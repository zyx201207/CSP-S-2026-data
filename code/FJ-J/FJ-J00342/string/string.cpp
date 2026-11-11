#include<bits/stdc++.h>
using namespace std;
char s[200005][3];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l=1,r=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		r+=s[i][1]-'0';
	}
	int ls=1,rs=n;//ls为第一组字符 rs为第二组字符 
	while(ls<=rs){
		if(l>=r){//当首比较的字符序号大于等于尾比较的字符时 说明比完了 
			break;
		}
		//首比较的一组字符比较完了就换下一组 
		if(l>s[ls][1]-'0'){
			ls++;
			l=1;
		} 
		//尾比较的一组字符比较完了就换下一组 
		if(r==0){
			rs--;
			r=s[rs][1];
		} 
		if(s[ls][2]!=s[rs][2]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
/*

3
2 a
2 b
1 c
//2

2
2 a
3 a
//0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
//3000000000

*/
