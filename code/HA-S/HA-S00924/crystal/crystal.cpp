#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int c[100001];
int p[100001];
void cha(){
	for(int i=1;i<n;i++)c[i] = a[i+1]-a[i];
}
void step1(int num){
	cha();//每次差值 
	
	
	int minx=0,minn=2147483647;
	for(int i = 1 ; i < n ; i++){
		if(c[i] < minn && c[i] != 0){
			minn = c[i]; minx = i;
		}
//		cout<<minn<<' '<<minx<<endl;
	}
	
	//检查2
	
	if(num - minn >= 0){
		p[minx]+=minn;
		a[minx]+=minn;
		c[minx]=0;
	}else{
		p[minx]+=num;
		a[minx]+=num;
		c[minx]=minn-num;
		num=0;
		return;
	}
	
	//检查
//	for(int i = 1; i <= n ; i ++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<c[i]<<' ';
//	}cout<<endl;
//	for(int i = 1 ; i<=n ;  i++){
//		cout<<p[i]<<' ';
//	}cout<<endl; 
//	
	
	
	
	num-=minn;
//	cout<<num<<' '<<minn<<' '<<minx<<endl;
	step1(num);
	
}
//aa数组
//for(int i=1;i<n;i++)cc[i] = aa[i+1]-aa[i];

//int step2(int xx,int yy,int aa[10001],int cc[10001],int pp[10001]){//开头结尾左右找 
//	for(int i = 1; i <= n ; i ++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<c[i]<<' ';
//	}cout<<endl;
//	for(int i = 1 ; i<=n ;  i++){
//		cout<<p[i]<<' ';
//	}cout<<endl<<'r'<<endl;
//
//
//	cout<<'p';//查验 
//
//
//	int xx1 = xx-1,yy1 = yy+1;
//	if(xx-1==0 || yy+1>n){
//		cout<<'p9';//查验 
//		if(yy1 > n && xx1 != 0){
//			for(int i = xx1-1 ; i > 0 ; i --){
//				cout<<'p';//查验 
//				for(int j=1;j<n;j++)cc[j] = aa[j+1]-aa[j];
//				if(cc[xx1]-pp[i] < 0){
//					aa[xx1]+=cc[xx1];
//					pp[i]-=cc[xx1];
//					break; 
//				}aa[xx1]+=pp[i];
//				pp[i]=0;
//			}if(cc[xx1] == 0) step2(xx1,yy,aa,cc,pp);
//		}
//		
//		
//		
//		
//		else if(yy1 <= n && xx1 == 0){
//			for(int i = yy1+1 ; i <= n ; i ++){
//				for(int j=1;j<n;j++)cc[j] = aa[j+1]-aa[j];
//				if(cc[yy]-pp[i] < 0){
//					aa[yy1]+=cc[yy];
//					pp[i]-=cc[yy];
//					break; 
//				}aa[yy1]+=pp[i];
//				pp[i]=0;
//			}if(cc[yy] == 0) step2(xx,yy1,aa,cc,pp);
//		}
//		
//		
//		
//		else{
//			cout<<4;
//			return (yy-xx+1);
//		}
//	}
//	
//	
//	
//	
//	
//	
//	
//	if(cc[xx1] > cc[yy]){
//		for(int i = 1 ; i <= n ; i ++){
//			for(int j=1;j<n;j++)cc[j] = aa[j+1]-aa[j];
//			if(i < xx1 && i > yy){
//				if(cc[xx1] - pp[i] <= 0){
//					aa[xx1] += cc[xx1];
//					pp[i] -= cc[xx1];
//					break;
//				}aa[xx1]+=pp[i];
//				pp[i]=0;
//			}
//		}if(cc[xx1] == 0){
//				step2(xx1,yy,aa,cc,pp);
//			}else return (yy-xx+1);
//	}
//	
//	
//	
//	
//	
//	else{
//		cout<<0;
//		
//		
//		for(int i = 1 ; i <= n ; i ++){
//			cout<<1;
//			for(int j=1;j<n;i++)cc[j] = aa[j+1]-aa[j];
//			if(i < xx && i > yy1){
//				if(cc[yy] - pp[i] <= 0){
//					aa[yy1] += cc[yy];
//					pp[i] -= cc[yy];
//					break;
//				}aa[yy1]+=pp[i];
//				pp[i]=0;
//			}
//		}if(cc[yy] == 0){
//				step2(xx,yy1,aa,cc,pp);
//			}else return (yy-xx+1);
//	}
//
//}
int step2n(int st,int ed,int a[100001],int c[100001],int p[100001]){
			int xx=st,yy=ed;
			while(xx>=1 && yy <= n){
				//cout<<xx<<"  "<<yy<<'p'<<endl;
				cha();
				
				
				
//				for(int i = 1; i <= n ; i ++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<c[i]<<' ';
//	}cout<<endl;
//	for(int i = 1 ; i<=n ;  i++){
//		cout<<p[i]<<' ';
//	}cout<<endl<<'/'<<endl;
//				cout<<c[xx-1]<<' '<<c[yy]<<endl;
				
				
				
				
				
				
				
				
				
				if(c[xx-1]<=c[yy]){
					for(int j = 1 ; j <= n ; j ++){
						
						if(j <= xx-1 || j >= yy){
							//cout<<'q'<<endl;
							cha();
							if(c[xx-1]-p[j] <= 0){
								a[xx-1]+=c[xx-1]; 
								p[j]-=c[xx-1];
								break;
							}else{
								a[xx-1]+=p[j];
								p[j]=0;
							}
						}
					}if(c[xx-1] == 0){
						xx--;
					}
				}
				
				
				
				
				else{
					for(int j = 1 ; j <= n ; j ++){
						if(j <= xx || j >= yy+1){
							cha();
							if(c[yy]-p[j] <= 0){
								a[yy+1]+=c[yy]; 
								p[j]-=c[yy];
								break;
							}else{
								a[yy+1]+=p[j];
								p[j]=0;
							}
						}
					}if(c[yy] == 0){
						yy++;
					}
				}
			}return yy-xx;
}
int step2nn(int st,int ed,int a[100001],int c[100001],int p[100001]){
			int xx=st,yy=ed;
			while(xx>=1 || yy <= n){
				//cout<<xx<<"  "<<yy<<'p'<<endl;
				cha();
				
				
				
				
				
				
				
				
				
				
				
				if(c[xx-1]<=c[yy] && xx>=1 || c[yy]==0){
					if(xx-1 <= 1) return yy-xx+1;
					
					for(int j = 1 ; j <= n ; j ++){
						
						if(j <= xx-1 || j >= yy){
							cha();
							if(c[xx-1]-p[j] <= 0){
								a[xx-1]+=c[xx-1]; 
								p[j]-=c[xx-1];
								break;
							}else{
								a[xx-1]+=p[j];
								p[j]=0;
							}
						}
					}if(c[xx-1] == 0){
						xx--;
						//return yy-xx+1;
					}
				}
				
				
				
				
				else if(c[xx-1]>c[yy] && yy<=n || c[xx-1]==0){
					if(yy+1 >= n) return yy-xx+1;
					for(int j = 1 ; j <= n ; j ++){
						if(j <= xx || j >= yy+1){
							cha();
							if(c[yy]-p[j] <= 0){
								a[yy+1]+=c[yy]; 
								p[j]-=c[yy];
								break;
							}else{
								a[yy+1]+=p[j];
								p[j]=0;
							}
						}
					}if(c[yy] == 0){
						yy++;
						//return yy-xx+1;
					}
				}
				else break;
			}return yy-xx;
}


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n ; i ++) cin >> a[i];
	//f1
	int ppp = a[1];
	
	//检查 
//	for(int i = 1; i <= n ; i ++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<c[i]<<' ';
//	}cout<<endl;
//	for(int i = 1 ; i<=n ;  i++){
//		cout<<p[i]<<' ';
//	}cout<<endl<<'/'<<endl;
	
	
	
	step1(m);
//	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
//	for(int i = 1; i <= n ; i ++){
//		cout<<c[i]<<' ';
//	}cout<<endl;
//	for(int i = 1 ; i<=n ;  i++){
//		cout<<p[i]<<' ';
//	}cout<<endl<<'/'<<endl;
	
	int cnt=-2147483647,st=1,ed=0;
	//找头尾验证  
	for(int i =2 ; i <= n+1 ; i ++){
		
		
		//cout<<st<<" "<<ed<<endl; 
		
		
		if(a[i] != a[st]){
			ed = i-1;
			if(ed == st){
				st=i;cnt=max(cnt,1);
				continue;
			}
			//cout<<st<<' '<<ed<<endl;
			cnt = max(cnt,step2n(st,ed,a,c,p));
			//else cnt = max(cnt,step2nn(st,ed,a,c,p));
			//cnt = max(cnt,ed-st+1);//min(cnt,step2(st,ed,a,c,p));
			
			
			
//			int xx=st,yy=ed;
//			while(xx>=1 || yy <= n){
//				cha();
//				if(c[xx-1]>=c[yy]]){
//					for(int j = 1 ; j <= n ; j ++){
//						if(j <= xx-1 && j >= yy){
//							cha();
//							if(c[xx-1]-p[j] <= 0){
//								a[xx-1]+=c[xx-1]; 
//								p[j]-=c[xx-1];
//								break;
//							}else{
//								a[xx-1]+=p[j];
//								p[j]=0;
//							}
//						}
//					}if(c[xx-1] == 0){
//						xx--;
//					}
//				}else{
//					for(int j = 1 ; j <= n ; j ++){
//						if(j <= xx && j >= yy+1){
//							cha();
//							if(c[yy]-p[j] <= 0){
//								a[yy+1]+=c[yy]; 
//								p[j]-=c[yy];
//								break;
//							}else{
//								a[yy+1]+=p[j];
//								p[j]=0;
//							}
//						}
//					}if(c[yy] == 0){
//						yy++;
//					}
//				}
//			}cnt=max(cnt,yy-xx+1);
			st = i;
		}
	}
	cout<<cnt;
	return 0;
} /*
5 5
1 2 4 8 9
数据
5 8
-3 -1 2 2 7
*/ 
