#include<bits/stdc++.h>
using namespace std;

long long num[200009];
char inputt[200009]={'-','-'};
int now=0;
 
//如果有不同的，输出该队头尾的最小权 
bool all_same_num=true;

char my_string(int n){
	int i=0;
	int sum=0;
	while(sum==n){
		i++;
		for(int j=1;j<=num[i]&&sum!=n;j++)sum++;
	}
	return inputt[i];
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int temp;cin >> temp;
		char temp2;
		cin >> temp2;
		if(temp2==inputt[now]){
			num[now]+=temp;
			if(num[now-1]!=num[now]-temp&&now!=1)all_same_num=true;
		}
		else {
			now++;
			num[now]=temp;
			inputt[now]=temp2;
			if(num[now-1]!=num[now]&&now!=1)all_same_num=false;
		}
	}
/*for(int i=1;i<=now;i++){
		cout << num[i] << inputt[i];
	}*/
	if(now==1){
		cout << 0;
		return 0;
	}else{
		bool ok=true;
		for (int i=1;i<=now;i++){
			if(inputt[i]!=inputt[now+1-i]){
				ok = false;
				break;
			}
			if(ok){
				cout << 0;
				return 0;
			}
		} 
	} 
	if(all_same_num){
		long long ans=0;
		int quan=num[1];
		for(int i=1;i<=now/2;i++){
			if(inputt[i]!=inputt[now+1-i]){
				ans+=quan;
			}
		}
		cout << ans;
		return 0;
	}else if(n==2){
		cout << min(num[1],num[2]);
		return 0;
	}else{
		long long ans=0;
		for(int i=1;i<=now/2;i++){
			if(my_string[i]!=my_string[now+1-i]){
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	
}
