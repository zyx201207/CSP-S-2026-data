#include<iostream>
#include<algorithm> 
#include<vector>
#include<deque>
using namespace std;

const int MAXN=5e5+5;

struct Data{
	int num;
	int cnt;
}; 

long long n,m,ans;
int a[MAXN];

deque<Data> dq;

void debug(){
	int len=(int)dq.size();
	for(int i=1;i<=len;i++){
		Data tmp=dq.front();
		cout<<tmp.num<<" "<<tmp.cnt<<endl;
		dq.pop_front();
		dq.push_back(tmp);
	}
	cout<<endl;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	int i=1;
	while(i<=n){
		int j=i+1;
		while(a[j]==a[i]){
			j++;
		}
		dq.push_back({a[i],j-i});
		i=j;
	}
	
//	debug();
	
	long long cnt=0;
	while(true){
		if(dq.size()==1){
			break;
		}
		Data tmp1=dq.front();
		dq.pop_front();
		Data tmp2=dq.front();
		dq.pop_front();
//		printf("取出两个数据 (num:%d, cnt:%d)  (num:%d, cnt:%d)\n",tmp1.num,tmp1.cnt,tmp2.num,tmp2.cnt); 
		if(cnt+(tmp2.num-tmp1.num)*tmp1.cnt<=m){
//			printf("操作贡献为 (%d-%d)*%d=%d\n",tmp2.num,tmp1.num,tmp1.cnt,(tmp2.num-tmp1.num)*tmp1.cnt);
			cnt+=(tmp2.num-tmp1.num)*tmp1.cnt;
//			printf("累加之后cnt的值 %d\n",cnt);
		}else{
			break;
		}
		tmp2.cnt+=tmp1.cnt;
		ans=tmp2.cnt;
//		printf("合并之后的数据 (num:%d,cnt:%d)\n",tmp2.num,tmp2.cnt);
		dq.push_front(tmp2);
	}
	cout<<ans<<'\n';
	
	return 0;
} 
