#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n;//由n段组成 
	cin>>n; 
	int x[n+10]={};//每段个数
	int y[n+10]={};//每段个数倒序 
	char a[n+10]={};//每段字母
	char b[n+10]={};//每段字母倒序
	for(int i=1,j=n;i<=n;i++,j--){//输入 
		cin>>x[i]>>a[i];
		y[j]=x[i];//倒序 
		b[j]=a[i];
	} 
	long long ans=0;//答案  
	for(int i=1,j=1;i<=n && j<=n;){//分别推进 
		if(x[i]==y[j]){//一样多 
			if(a[i]!=b[j]){//字母不同 
				ans+=x[i];//要修改的次数增加 
			} 
			i++;//两个同时推进 
			j++; 
			
		}else if(x[i]>y[j]){//x组多 
			if(a[i]!=b[j]){//字母不同
				ans+=x[i]-y[j];//要修改的次数增加 
			}
			x[i]-=y[j];//x的数量更新 
			j++;//推进y组 
			
		}else{//y组多 
			if(a[i]!=b[j]){//字母不同
				ans+=y[j]-x[i];//要修改的次数增加 
			}
			y[j]-=x[i];//y的数量更新 
			i++;//推进y组 
		}
		 
	}
	cout<<ans/2;
	return 0;
} 
//人生南北多歧路 君向潇湘我向秦 
