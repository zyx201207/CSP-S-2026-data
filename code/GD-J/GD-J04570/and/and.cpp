#include<bits/stdc++.h>
using namespace std;
int n,m,cnt1=3e8;
vector<long long> a(2e5+100);
long long f(int bh,long long ans,int end_a){
//	printf("in:%d %d %d\n",bh,ans,end_a);//
	if(bh==m){
//		printf("out1:%d\n",ans);//
		return ans;
	}
	long long f_ans=-1;
	for(int i=end_a-1;i>=0;i--){
		cnt1--;
			if(cnt1<=0){
				return f_ans;
			}
//	printf("for:%d %d %d %d %d %d\n",bh,i,a[i],ans,(ans&a[i]),f_ans);//
		f_ans=max(f(bh+1,ans&a[i],i),f_ans);
		if(cnt1<=0){
				return f_ans;
			}
		if(i>0&&ans!=-1&&(ans&a[i]>a[i-1])){
			break;
		}
	}
//		printf("out2:%d\n",f_ans);//
	return f_ans;
}
int main(){
	ifstream in("and.in");
	ofstream out("and.out");
//	
	in>>n>>m;
	for(int i=0;i<n;i++){
		in>>a[i];
//		cout<<a[i]<<' ';//
	}
//	cout<<endl;//
	sort(a.begin(),a.begin()+n);
	out<<f(0,(1<<63)-1,n);
	return 0;
} 
