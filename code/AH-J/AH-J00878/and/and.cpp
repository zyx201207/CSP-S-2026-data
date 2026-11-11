#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans=-1145141919810;
void dfs(long long all/*选了多少个数*/,long long now/*当前所在a*/,long long sum/*总与值*/){
	if(now==n){
		if(all==m)ans=max(ans,sum);
		return;
	}
	if(all==m){
		ans=max(ans,sum);
		return;
	}
	
	dfs(all+1,now+1,sum&a[now]);//选
	dfs(all,now+1,sum);//不选
	return;
}
int main(){
	freopen("and.in","r",stdin);//注释删除！！！！！！！！！！！！！
	freopen("and.out","w",stdout);//注释删除！！！！！！！！！！！！！
	cin>>n>>m;
	if(n<=24){
		for(long long i=0;i<n;i++)cin>>a[i]; 
		dfs(0,0,(1ll<<40ll)-1);//一定能与第一个数相同
		cout<<ans;
		return 0;
	}else{
		if(n==m){
			long long cut=(1ll<<40ll)-1;
			for(long long i=0;i<n;i++){
				cin>>a[i]; 
				cut&=a[i];
			}
			cout<<cut;
			return 0;
		}else if(m==1){
			long long cut=-78919178666114514;
			for(long long i=0;i<n;i++){
				cin>>a[i]; 
				cut=max(cut,a[i]);
			}
			cout<<cut;
			return 0; 
		}else if(m==2){
			long long cut=-78919178666114514;
			for(long long i=0;i<n;i++)cin>>a[i]; 
			for(long long i=0;i<n-1;i++)for(long long j=i+1;j<n;j++)cut=max(cut,a[i]&a[j]);
			cout<<cut;
			return 0; 
		}
	}
	//now 10:15.
	//I am tired.
	//Konjac.
	//is it me?Yes?
	//I can't solve Topic 2.only 48.
	//Konjac.
	//Fake.Joke.
	//But I'm trying.Trying.Trying!
	//Maybe I have lost hope.
	//Maybe I lost will.
	//Maybe I forget real.
	//But I am what I am.
	//TRY_____FOR_______ME________I'M____TRY
	//No hope?Just do it.
	//Impossible=>I'm possible.
	//(Topic 2:?What do you say?Hahahahaha......)
	//My information race dream,disappearing.
	//Badbye,my dream.
	//Hope to see you again.
	//Exit the game ------> |door|
	//Back home I will sleeeeeeeeeeeeeeeeeeeeep!
	
	//uid:1809725
	//who can find this?Haqi!
	return 0;
}
