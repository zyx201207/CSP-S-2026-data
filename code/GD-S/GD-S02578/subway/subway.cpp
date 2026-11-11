#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int w[501],k[501],a[501][500001],t[501][500001];

signed main()
{	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(0<=c&&c<=11)
	{	int huan[501][501],pd[501][501];
		memset(huan,-1,sizeof(huan));
		memset(pd,0,sizeof(pd));
		for(int i=1;i<=m;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++)
		{	cin>>k[i];
			for(int j=1;j<=2*k[i];j++)
				cin>>a[i][j]>>t[i][j];
			pd[a[i][1]][a[i][2]]=pd[a[i][2]][a[i][1]]=1;
			huan[a[i][1]][a[i][2]]=huan[a[i][2]][a[i][1]]=0;
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i][1]==a[j][1])
				{	huan[i][j]=huan[j][i]=t[i][1]+t[j][1];
					pd[i][j]=pd[j][i]=1;
				}
				else if(a[i][2]==a[j][1])
				{	huan[i][j]=huan[j][i]=t[i][2]+t[j][1];
					pd[i][j]=pd[j][i]=1;
				}
				else if(a[i][2]==a[j][2])
				{	huan[i][j]=huan[j][i]=t[i][2]+t[j][2];
					pd[i][j]=pd[j][i]=1;
				}
				else if(a[i][1]==a[j][2])
				{	huan[i][j]=huan[j][i]=t[i][1]+t[j][2];
					pd[i][j]=pd[j][i]=1;
				}
		while(q--)
		{	int st,ed;
			cin>>st>>ed;
			int ans=w[st]+w[ed],res=1e9;
			if(pd[st][ed])
				cout<<ans+huan[st][ed]<<"\n";
			else
			{	for(int i=1;i<=n;i++)
					if(i!=st&&i!=ed&&pd[i][st]&&pd[i][ed])
						res=min(huan[i][st]+huan[i][ed],res);
				cout<<ans+res<<"\n";
			}
		}
	}
	else
	{	for(int i=1;i<=m;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++)
		{	cin>>k[i];
			for(int j=1;j<=2*k[i];j++)
				cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
//goodbye OI
//编译单个文件...
//--------
//- 文件名: D:\csps-new\down\subway\cur.cpp
//- 编译器名: TDM-GCC 4.9.2 64-bit Release
//
//处理 C++ 源文件...
//--------
//- C++ 编译器: C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe
//- 命令: g++.exe "D:\csps-new\down\subway\cur.cpp" -o "D:\csps-new\down\subway\cur.exe" -ansi -g3 -O2 -std=c++14 -static -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include\c++" -L"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib" -L"C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib" -static-libgcc -g3
//D:\csps-new\down\subway\cur.cpp: In function 'int main()':
//D:\csps-new\down\subway\cur.cpp:11:32: warning: array of array of runtime bound [-Wvla]
//  { int w[m+1],k[n+1],a[n+1][m+1],t[n+1][m+1],huan[n+1][n+1],pd[n+1][n+1];
//                                ^
//
//D:\csps-new\down\subway\cur.cpp:11:44: warning: array of array of runtime bound [-Wvla]
//  { int w[m+1],k[n+1],a[n+1][m+1],t[n+1][m+1],huan[n+1][n+1],pd[n+1][n+1];
//                                            ^
//D:\csps-new\down\subway\cur.cpp:11:59: warning: array of array of runtime bound [-Wvla]
//  { int w[m+1],k[n+1],a[n+1][m+1],t[n+1][m+1],huan[n+1][n+1],pd[n+1][n+1];
//                                                           ^
//D:\csps-new\down\subway\cur.cpp:11:72: warning: array of array of runtime bound [-Wvla]
//  { int w[m+1],k[n+1],a[n+1][m+1],t[n+1][m+1],huan[n+1][n+1],pd[n+1][n+1];
//                                                                        ^
//D:\csps-new\down\subway\cur.cpp:12:29: warning: taking sizeof array of runtime bound [-Wvla]
//   memset(huan,-1,sizeof(huan));
//                             ^
//D:\csps-new\down\subway\cur.cpp:13:24: warning: taking sizeof array of runtime bound [-Wvla]
//   memset(pd,0,sizeof(pd));
//                        ^
//
//
//编译结果...
//--------
//- 错误: 0
//- 警告: 6
//- 输出文件名: D:\csps-new\down\subway\cur.exe
//- 输出大小: 1.97363185882568 MiB
//- 编译时间: 0.53s
//这是什么 

//--------------------------------
//Failed to execute "D:\csps-new\down\subway\cur.exe":
//Error 0: 操作成功完成。
//
//请按任意键继续. . .
//这又是啥 ???
//cur.exe无法在你的设备上运行?????
//我***这啥啊 
