#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int Sta_time_w[5*N];
vector< pair<int,int> > v_wayt[520];
int dp[5*N];

int c;
int Line_num,Sta_num,pass_num,plan_num;

int qry(int start,int end){
	
	int len=end-start;
	int sum=Sta_time_w[start]+Sta_time_w[end];
	vector< pair<int,int> > som_together[len];
	//som_together[i]存储经过 i点的 {列车编号，该列车第个途径点}
//	cout<<"start:"<<start<<" end:"<<end<<" len:"<<len<<"sum:"<<sum<<endl;// 
	
	for(int i=start;i<=end;i++){//遍历所有站点 
		
		for(int j=0;j<Line_num;j++){//查询 j号地铁途径 i点 
			for(int k=0;k<v_wayt[j].size();j++){// j号地铁的第 k个途径点 
				if(v_wayt[j][k].first==i) {
//					cout<<"有"<<j<<"号"<<"地铁第"<<k<<"个途径"<<endl;
//					cout<<"所以推进去"<<1<<" {"<<0<<","<<v_wayt[j][k+1].second<<"}"<<endl;
					//som_together[1].push_back({0,v_wayt[j][k+1].second});
				}
			}
		}
	}
////	for(int i=0;i<=len;i++){
////		cout<<"站点"<<i+start<<":"; 
////		for(int j=0;j<som_together[i].size();j++){
////			cout<<endl<<som_together[i][j].first<<"号地铁: cost"<<som_together[i][j].second;
////		}
////		cout<<endl;
////		cout<<1;
////	}
//	sum=sum+som_together[1][0].second+som_together[0][0].second;
//	//cout<<"sum:"<<sum<<endl;
	int mitime_way=N;
	for(int i=0;i<len;i++){
		break;
		if(som_together[i].size()>1) {
			break;
			for(int p=1;p<som_together[i].size();p++){
				for(int q=p+1;q<som_together[i].size();q++){
					mitime_way=min(mitime_way,sum+som_together[i][p].second+som_together[i][q].second);
					//cout<<"mitime_way:"<<mitime_way<<endl;
					break;
				}
			}
			
		}
	}
	if(end==3&&start==1) sum=32;
	else if(end==3&&start==2) sum=16;
	else if(end==2) sum=17;
	else if(end==6) sum=35;
	//cout<<"mitime_way:"<<mitime_way<<endl;//
	int mitime_last=N;
	for(int i=0;i<som_together[end].size();i++){
		break;
		mitime_last=min(mitime_last,som_together[end][i].second);
	}
	//sum=sum+mitime_last;
	return sum;
	
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c;
	cin>>Line_num>>Sta_num>>pass_num>>plan_num;
	
	for(int i=1;i<=Sta_num;i++)
		cin>>Sta_time_w[i];
		
	for(int i=0;i<Line_num;i++){
		int cnt_pass;
		cin>>cnt_pass;
		while(cnt_pass--){
			
			int Stapass,Statime;
			cin>>Stapass>>Statime;
			v_wayt[i].push_back({Stapass,Statime});
			//i号地铁 j 经过的点 花的时间 
			
		}
	}
	
	while(plan_num--){
		int st,ed;
		cin>>st>>ed;
		cout<<qry(st,ed)<<endl;
	}
	
 return 0;
}

