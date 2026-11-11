#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	int a;
	string b;
	int bw;
	boal be;
	int c;
	string d;
	int dw;
	boal de;
	int aq;
	int bq;
	int cq;
	int dq;
	int k;
	in t;
	k=0;
	t=0;
	int l;
	l=0;
	aq=0;
	bq=0;
	cq=0;
	dq=0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	bw=b;
	be=b;
	dw=d;
	de=d;
	if(a==c)
	{
		aq=1;
	}	
	if(aq==1)
	{
		if(bw==dw)
		{
			bq=1;
		}
	}
	if(bq==1)
	{
		if(be<='C')
		{
			k=1;
		}
		if(de<='C')
		{
			t=1;
		{
		}
		if(k==t)
			cq=1;
		}
	}
	if(cq==1)
	{
		l=be-de;
		if(l==1)
		{
			dq=1;
		}
		if(l==-1)
		{
			dp=1;
		}
	}
	cout <<aq<< <<bq<< <<cq<< <<dq<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
