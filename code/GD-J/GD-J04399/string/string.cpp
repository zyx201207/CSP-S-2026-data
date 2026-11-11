#include<bits/stdc++.h>
using namespace std;
//先输入，双指针
//一个从头，一个从末尾
//如果字母不同，就把大的减去小的
//相同就同时移位
// 不同时移位要费用
struct digit{
	long long x;
	char c;
}; 
digit a[200020];
long long n,sum; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x; 
	}
	long long r = sum,l = 1,ans = 0,r1 = n,l1 = 1;
	while(r>l){
		
		if(a[r1].c!=a[l1].c){ 
			if(a[r1].x>a[l1].x){
				ans+=a[l1].x;
				r-=a[l1].x;
				l+=a[l1].x;
				l1++;
			}else if(a[r1].x<a[l1].x){
				ans+=a[r1].x;
				r-=a[r1].x;
				l+=a[r1].x;
				r1--;
			}else{
				//cout<<ans<<endl;
				//直接跳容易脚快跳太多
				//要加个限制
				//一个一个跳会超时
				//那就跳完之后再反悔
				//多跳的把答案减回去 
				while(l!=r&&a[r1].x!=0){
					l++;
					r--;
					ans++;
					a[r1].x--;
				}
				r1--;
				l1++;
			}
		}else{
			if(a[r1].x>a[l1].x){
				r-=a[l1].x;
				l+=a[l1].x;
				l1++;
			}else if(a[r1].x<a[l1].x){
				r-=a[r1].x;
				l+=a[r1].x;
				r1--;
				
			}else{
				while(l!=r&&a[r1].x!=0){
					l++;
					r--;
					a[r1].x--;
				}
				r1--;
				l1++;
			}	
		}
	}
	cout<<ans;
	return 0;
}

