#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const int N=200005;
long long n,ans;
long long left_w;   //左边界（包含）    位置 
long long right_w;  //右边界（包含）    位置 
long long left_i;   //左边界（包含）    坐标 
long long right_i;  //右边界（包含）    坐标 
struct stu{
	long long nt;//字符个数
	char ch;//字符 
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

//--------------------------------------------------
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nt>>a[i].ch;
		right_w+=a[i].nt;
	}
//--------------------------------------------------
	left_i=1;
	right_i=n;
	left_w=1;
	while(left_w<right_w){
		if(a[left_i].nt>a[right_i].nt){//左多 
			if(a[left_i].ch==a[right_i].ch){//特判   左=右   字符 
				left_w+=a[right_i].nt;
				a[left_i].nt-=a[right_i].nt;
				right_w-=a[right_i].nt;
				right_i--;
			}
			left_w+=a[right_i].nt;
			a[left_i].nt-=a[right_i].nt;
			ans+=a[right_i].nt;
			right_w-=a[right_i].nt;
			right_i--;
		}else if(a[left_i].nt<a[right_i].nt){//右多 
			if(a[left_i].ch==a[right_i].ch){//特判   左=右    字符 
				right_w-=a[left_i].nt;
				a[right_i].nt-=a[left_i].nt;
				left_w+=a[left_i].nt;
				left_i++;
			}
			right_w-=a[left_i].nt;
			a[right_i].nt-=a[left_i].nt;
			ans+=a[left_i].nt;
			left_w+=a[left_i].nt;
			left_i++;
		}else{//一样多 
			if(a[left_i].ch==a[right_i].ch){//特判   左=右    字符 
				left_i++;
				right_i--;
				left_w+=a[left_i].nt;
				right_w-=a[left_i].nt;
			}
			ans+=a[left_i].nt;
			left_i++;
			right_i--;
			left_w+=a[left_i].nt;
			right_w-=a[left_i].nt;
		}
	}
	cout<<ans<<endl;
	return 0;
}
