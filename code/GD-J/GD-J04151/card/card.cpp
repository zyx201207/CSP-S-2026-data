/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N],last[N],ans[N],mark[N];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		if(last[a[i]] == 0){
			
			last[a[i]] = i;
			printf("ts:a[%d] = %d,新入牌,现在%d上一次的位置在%d\n",i,a[i],a[i],last[a[i]]);
			for(int j = i;j >= 1;j--){
				if(mark[j]) continue;
				ans[a[j]]++;
				printf("1	ts:ans[%d(a[%d])]++,=%d\n",a[j],j,ans[a[j]]);
			}
		}else{
			printf("ts:a[%d] = %d,回收牌,%d上一次的位置在%d\n",i,a[i],a[i],last[a[i]]);
			for(int j = i-1;j > last[a[i]];j--){
				if(mark[j]) continue;
				last[a[j]] = 0;
				mark[j] = 1;
				printf("ts:mark[%d] = 1\n",j);
				printf("	ts:last[%d(a[%d])]=0\n",a[j],j);
			}
			mark[i] = 1;
			printf("ts:mark[%d] = 1\n",i);
			for(int j = last[a[i]];j >= 1;j--){
				puts("!!!");
				printf("需要加：%d\n",j);
				if(mark[j] == 0){
					ans[a[j]]++;
					printf("2	ts:ans[%d(a[%d])]++,=%d\n",a[j],j,ans[a[j]]);
				}
				
				
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/


#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N],last[N],ans[N],mark[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= 1;i--){
		if(last[a[i]] == 0){
			
			last[a[i]] = i;
//			printf("ts:a[%d] = %d,新入牌,现在%d上一次的位置在%d\n",i,a[i],a[i],last[a[i]]);
			for(int j = i;j <= n;j++){
				if(mark[j]) continue;
				ans[a[j]]++;
//				printf("1	ts:ans[%d(a[%d])]++,=%d\n",a[j],j,ans[a[j]]);
			}
		}else{
//			printf("ts:a[%d] = %d,回收牌,%d上一次的位置在%d\n",i,a[i],a[i],last[a[i]]);
			for(int j = i+1;j < last[a[i]];j++){
				if(mark[j]) continue;
				last[a[j]] = 0;
				mark[j] = 1;
//				printf("ts:mark[%d] = 1\n",j);
//				printf("	ts:last[%d(a[%d])]=0\n",a[j],j);
			}
			mark[i] = 1;
//			printf("ts:mark[%d] = 1\n",i);
			for(int j = last[a[i]];j <= n;j++){
//				puts("!!!");
//				printf("需要加：%d\n",j);
				if(mark[j] == 0){
					ans[a[j]]++;
//					printf("2	ts:ans[%d(a[%d])]++,=%d\n",a[j],j,ans[a[j]]);
				}
				
				
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

